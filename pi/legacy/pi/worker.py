from pimqtt import PiMQTT
import sched, time

pimqtt = None

def work(sc): 
    pimqtt.publish_to_cloud()
    scheduler.enter(1, 1, work, (sc,))

if __name__ == "__main__":
    pimqtt = PiMQTT()

    scheduler = sched.scheduler(time.time, time.sleep)
    scheduler.enter(2, 1, work, (scheduler,))
    scheduler.run()