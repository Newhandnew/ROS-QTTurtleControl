/**
 * @file /include/qtest/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qtest_QNODE_HPP_
#define qtest_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <diagnostic_msgs/KeyValue.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtest {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();
	void sendVel(double angular, double linear);
	void sendCommand(const std::string &message);
    void robotCome(void);
	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();

    void openhabUpdated();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
	ros::Publisher command_publisher;
	ros::Subscriber openhab_subscriber;
    QStringListModel logging_model;

    void openhabCallback(const diagnostic_msgs::KeyValue& msg);

};

}  // namespace qtest

#endif /* qtest_QNODE_HPP_ */
