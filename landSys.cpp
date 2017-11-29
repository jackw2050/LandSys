#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"



float readAnalog(int number) {
	stringstream ss;
	ss << LDR_PATH << number << "_raw";
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> number;
	fs.close();
	cout << "value is " << number << endl;
	float voltage = 1.8 * (number / 4095.0);
	return voltage;
}

int main(int argc, char* argv[]) {
	cout << "Starting the readLDR program" << endl;
	float value = readAnalog(0);
	cout << "Voltage is  " <<  value << endl;
	return 0;
}
