#include<iostream>
#include<ros/ros.h>
#include<std_msgs/String.h>

using namespace std;
ros::Publisher pub;
ros::Subscriber sub;
std_msgs::String chat2;

void callback2(const std_msgs::StringConstPtr &msg1)
{
	//cout<<endl;
        cout<<"Terminal 1 : "<<msg1->data<<endl;
}

int main(int argc, char **argv)
{
        ros::init(argc, argv, "terminal_2");
        ros::NodeHandle n;
	//ros::spin();
        pub = n.advertise<std_msgs::String>("t2",10);
        sub = n.subscribe("t1", 10, &callback2);

	while(ros::ok())
	{
		cout<<"Terminal 2 : ";
        	cin>>chat2.data;
        	cout<<endl;
        	std_msgs::String msg2;
        	msg2.data = chat2.data;
        	pub.publish(msg2);
		//cout<<endl;
		ros::spinOnce();
        }

        ros::waitForShutdown();

        return 0;
}
