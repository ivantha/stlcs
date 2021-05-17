import paho.mqtt.client as mqtt


class PiMQTT:
    def __init__(self):
        self.sensors = [[[0] * 5] * 6] * 4  # 5 sensors * 6 lanes * 4 roads

        self.pi_mac = "001c42146bac"

        self.mqtt_cloud = mqtt.Client()
        self.mqtt_pi = mqtt.Client()

        # Enable debug messages
        self.mqtt_cloud.on_log = self.on_log
        self.mqtt_pi.on_log = self.on_log

        # Connect to the Cloud MQTT broker
        pass

        # Connect to the Pi Broker
        # self.mqtt_pi.connect("raspberrypi.local", 1883, 60)
        self.mqtt_pi.connect("localhost", 1883, 60)

        # self.mqtt_cloud.on_message = self.on_message_cloud
        self.mqtt_pi.on_message = self.on_message_pi

        # Start subscribe to Cloud Broker, with QoS level 0
        # self.mqtt_cloud.subscribe("pi/" + self.pi_mac + "/cmd", 0)
        # self.mqtt_cloud.loop_start()

        # Start subscribe to Pi Broker, with QoS level 0
        self.mqtt_pi.subscribe("local/+/data", 0)   # local/road_id/data
        self.mqtt_pi.loop_start()

    # On log function
    def on_log(self, client, obj, level, string):
        print(string)

    # On message from Cloud-channel
    def on_message_cloud(self, client, userdata, msg):
        # <road_id>:<lane_id>:<d><d>
        # off 00
        # red 01
        # yellow 10
        # green 11
        print("Command recieved from cloud: " + str(msg))
        cmds = msg.payload.decode().split(":")
        self.publish_to_pi(cmds[0], cmds[1], cmds[2])

    # On message from Pi-channel
    def on_message_pi(self, client, userdata, msg):
        # Process all messages from arduinos
        print("Pi broker message: " + str(msg.payload.decode()))

    # Publish data to Cloud-channel
    def publish_to_cloud(self):
        print("Publishing to cloud....:")
        # for road_index in range(4):
        #     for lane_index in range(4):
        #         print("Road {} - Lane {} -".format(road_index, lane_index, self.sensors[road_index][lane_index]))
        # self.mqtt_cloud.publish("pi/" + self.pi_mac + "/data", self.sensors)

    # Publish commands to Pi-channel
    def publish_to_pi(self, road_no, lane_no, cmd):
        print("Publishing to pi....: " + str(road_no) + "  " + str(lane_no) + "  " + str(cmd))
        self.mqtt_pi.publish("local/" + str(road_no) + "/cmd", str(lane_no) + ":" + cmd)
