#include "RobotMap.h"

void RobotMap::init() {
    spark_port_1 = std::make_shared<Spark>(Spark(1));
    spark_port_2 = std::make_shared<Spark>(Spark(2));
}
