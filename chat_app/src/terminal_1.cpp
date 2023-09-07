#include<iostream>
#include<ros/ros.h>
#include<std_msgs/String.h>

using namespace std;
ros::Publisher pub;
ros::Subscriber sub;

void callback1(const std_msgs::StringConstPtr &msg2)
{
	//cout<<endl;
        cout<<"Terminal 2 : "<<msg2->data<<endl;
}

int main(int argc, char **argv)
{
        ros::init(argc, argv, "terminal_1");
        ros::NodeHandle n;
	//ros::spin();
        pub = n.advertise<std_msgs::String>("t1",10);
        sub = n.subscribe("t2", 10, &callback1);
        std_msgs::String chat1;

        while(ros::ok())
        {
		cout<<"Terminal 1 : ";
                cin>>chat1.data;
                cout<<endl;
                std_msgs::String msg1;
                msg1.data = chat1.data;
                pub.publish(msg1);
		//cout<<endl;
		ros::spinOnce();
	}

	ros::waitForShutdown();

        return 0;
}

