import paho.mqtt.client as mqtt
import os, urlparse, psutil

class PiMQTT:
    def __init__(self):
        self.n1_traffic = 0
        self.n2_traffic = 0
        self.n3_traffic = 0
        self.n4_traffic = 0
        self.n5_traffic = 0
        self.n6_traffic = 0

        self.e1_traffic = 0
        self.e2_traffic = 0
        self.e3_traffic = 0
        self.e4_traffic = 0
        self.e5_traffic = 0
        self.e6_traffic = 0

        self.s1_traffic = 0
        self.s2_traffic = 0
        self.s3_traffic = 0
        self.s4_traffic = 0
        self.s5_traffic = 0
        self.s6_traffic = 0

        self.w1_traffic = 0
        self.w2_traffic = 0
        self.w3_traffic = 0
        self.w4_traffic = 0
        self.w5_traffic = 0
        self.w6_traffic = 0

        self.pi_mac = "001c42146bac"

        self.mqtt_cloud = mqtt.Client()
        self.mqtt_pi = mqtt.Client()

        # Enable debug messages
        self.mqtt_cloud.on_log = self.on_log
        self.mqtt_pi.on_log = self.on_log

        # Parse CLOUDMQTT_URL 
        url_str = 'mqtt://qvyfpyry:KWH_IFxUDb0g@m14.cloudmqtt.com:18041'
        url = urlparse.urlparse(url_str)
        # Connect to the Cloud Broker
        self.mqtt_cloud.username_pw_set(url.username, url.password)
        self.mqtt_cloud.connect(url.hostname, url.port)

        # Connect to the Pi Broker
        self.mqtt_pi.connect("raspberrypi.local", 1883, 60)

        self.mqtt_cloud.on_message = self.on_message_cloud
        self.mqtt_pi.on_message = self.on_message_pi

        # Start subscribe to Cloud Broker, with QoS level 0
        self.mqtt_cloud.subscribe("pi/" + self.pi_mac + "/cmd", 0)
        self.mqtt_cloud.loop_forever()

        # Start subscribe to Pi Broker, with QoS level 0
        self.mqtt_pi.subscribe("local/+/data", 0)

    # On log function
    def on_log(self, client, obj, level, string):
        print(string)

    # On message from Cloud Broker
    def on_message_cloud(self, client, userdata, msg):
        # <road_id>:<lane_id>:<d><d>
        # off 00
        # red 01
        # yellow 10
        # green 11
        print("Command recieved from cloud: " + str(msg))
        cmds = msg.payload.decode().split(":")
        self.publish_to_pi(cmds[0], cmds[1], cmds[2])  

    # Publish data to Cloud Broker
    def publish_to_cloud(self):
        density_data = ""

        density_data += ":" + str(self.n1_traffic)
        density_data += ":" + str(self.n2_traffic)
        density_data += ":" + str(self.n3_traffic)
        density_data += ":" + str(self.n4_traffic)
        density_data += ":" + str(self.n5_traffic)
        density_data += ":" + str(self.n6_traffic)

        density_data += ":" + str(self.e1_traffic)
        density_data += ":" + str(self.e2_traffic)
        density_data += ":" + str(self.e3_traffic)
        density_data += ":" + str(self.e4_traffic)
        density_data += ":" + str(self.e5_traffic)
        density_data += ":" + str(self.e6_traffic)

        density_data += ":" + str(self.s1_traffic)
        density_data += ":" + str(self.s2_traffic)
        density_data += ":" + str(self.s3_traffic)
        density_data += ":" + str(self.s4_traffic)
        density_data += ":" + str(self.s5_traffic)
        density_data += ":" + str(self.s6_traffic)

        density_data += ":" + str(self.w1_traffic)
        density_data += ":" + str(self.w2_traffic)
        density_data += ":" + str(self.w3_traffic)
        density_data += ":" + str(self.w4_traffic)
        density_data += ":" + str(self.w5_traffic)
        density_data += ":" + str(self.w6_traffic)
       
        print("Publishing to cloud....: " + density_data)
        self.mqtt_cloud.publish("pi/" + self.pi_mac + "/data", self.pi_mac + density_data)

    # On message from Pi Broker
    def on_message_pi(self, client, userdata, msg):
        # Process all messages from arduinos
        print("Pi broker message" + str(msg))

    # publish commands to Pi
    def publish_to_pi(self, road_no, lane_no, cmd):
        print("Publishing to pi....: " + str(road_no) + "  " + str(lane_no) + "  " + str(cmd))
        self.mqtt_pi.publish("local/" + road_no + "/cmd", lane_no + ":" + cmd)

        