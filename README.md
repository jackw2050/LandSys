# LandSys
Land meter embedded system software for Beaglebone Black

Beaglebone Black setup and software installation.





 
Connecting to Beaglebone

Puty
root@beaglebone:~#    

Chrome
root@beaglebone:\var/lib/cloud9#    






Enabling Wifi and connecting to server.

root@beaglebone:\var/lib/cloud9#    sudo connmanctl
connmanctl> enable wifi
Enabled wifi
connmanctl> scan wifi
Scan completed for wifi
connmanctl> services
connmanctl> agent on

Agent registered

connmanctl> connect wifi_506583d4fc5e_544e434150413937414239_managed_psk

Use the information for Togakure.  It will be different that above

Passphrase? Tomoko43maruyama

connected wifi_506583d4fc5e_544e434150413937414239_managed_psk
connmanctl> quit

You should now be connected to your local wifi. You can check that you have an IP address by typing the following in the terminal window:
ifconfig –a




Updating system software.

apt-get update



Loading environment


ADAFRUIT_BBIO

https://pypi.python.org/pypi/Adafruit_BBIO
root@beaglebone:~# pip install --upgrade Adafruit_BBIO


Setting Processor Speed

Getting current info

cpufreq-info

Setting CPU Frequency

sudo cpufreq-set -f 600MHz


Creating New User

useradd [options] username
sudo useradd zls
sudo passwd username   You will be prompted with new password for user




Loading program

GIT
root@beaglebone:~# sudo apt-get install git   

 https://github.com/jackw2050/land_max1300


root@beaglebone:~#  git clone https://github.com/jackw2050/land_max1300



Enabling program to auto run

Set Date and Time

root@beaglebone:\var/lib/cloud9#    date –s “21 JULY 2017 14:09:50”
or
root@beaglebone:\var/lib/cloud9#    date –-set= “21 JULY 2017 14:09:50”

Fri Jul 21 14:09:50 UTC 2017

root@beaglebone:\var/lib/cloud9#    




Setting up RSA for git

https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/


https://help.github.com/articles/adding-a-new-ssh-key-to-your-github-account/


To copy the public key use:
Cat ~/.ssh/id_rsa.pub


Beagleboard:MicroSD As Extra Storage
http://elinux.org/Beagleboard:MicroSD_As_Extra_Storage

Procedure
These instructions are meant to be executed in Angstrom's GUI on your BeagleBone Black. If you have another Linux computer you may be able to use its Disk Utility in these instructions as well.
1. Using a USB adapter, insert the microSD into a USB hub on your BeagleBone Black (along with a mouse and keyboard)
2. Open up Disk Utility
•	Applications > System Tools > Disk Utility
3. Unmount the microSD volume along with any other volumes you don't want to keep
4. Click Format Drive and format the drive
•	Scheme: Master Boot Record is fine
•	Warning this erases everything on the drive
5. Select the Free section under 'Volumes' and then click Create Partition
6. Make the size as large as you want and make sure the type is FAT. Name it whatever you would like and click 'Create'
7. Mount the volume you just created by clicking Mount Volume
8. Open the the volume with the file explorer and create a new file in it named uEnv.txt
9. Right Click > Create Document > Empty File
10. Open uEnv.txt and fill it with the following 4 lines of code:
mmcdev=1 bootpart=1:2 mmcroot=/dev/mmcblk1p2 ro optargs=quiet 
11. Save the file and shutdown your BeagleBone Black
12. Remove the microSD from the USB hub and insert it into the microSD slot on the BeagleBone Black
13. Apply power to your BeagleBone Black and when its starts you should have the microSD mounted as available storage.


Installing Linux on SD card


http://elinux.org/Beagleboard:BeagleBoneBlack_Debian






Enabling Bluetooth on beagle Bone Black



In enabling Bluetooth is to inform BeagleBone Black that we would like to be able to use this feature. To do this we will just need to make a quick edit to a configuration file. If we perform: 

cat /var/lib/connman/settings 

then we see something like this 

[global] 

OfflineMode=false

[Wired] 

Enable=true 

[WiFi] 

Enable=true

This file is essentially telling us that the Beagle bone Black connection manager is only aware of Wired Ethernet connections, or WiFi connections enabled through a USB module. If we want to do is add the Bluetooth module. To add this just type the following command:

echo –e “\n[Bluetooth]\nEnable=true” >> /var/lib/connman/settings 

Now if we look at your configuration file again by using 

cat /var/lib/connman/settings 

We would see something like this 

[global] 

OfflineMode=false 

[Wired] 

Enable=true 

[WiFi] 

Enable=true 

[Bluetooth] 

Enable=true 

If this worked, then we can move on to the next step. The next step is to enable and start the system service that monitors Bluetooth. This allows pairing with the BeagleBone Black, as well as some other core functionality. 
To enable the service type: 

systemctl enable bluetooth.service



Other references:

https://cmumrsdproject.wikispaces.com/Bluetooth+Socket+Programming+using+Python+PyBluez

https://github.com/adafruit/Adafruit_Python_BluefruitLE

http://www.zephyr-labs.com/?p=87

https://pypi.python.org/pypi/bgapi/0.3

http://forum.rfduino.com/index.php?topic=73.0

http://www.interdigital.com/post/ship-iot-with-beaglebone-black-ti-sensortags-and-devicehive



C/C++ Compiling and Linking

Program file name = helloWorld.cpp

C Programs
To Compile

gcc helloWorld.c –o helloWorldc 

To Run

./helloWorldc

C++ Programs
To Compile

g++ helloWorld.cpp –o helloWorldcpp 

To Run

./helloWorldcpp



Device Tree Overlay

Overlays are located at: /lib/firmware

You can load the overlays in the /boot/uEnv.txt file

To list overlays: cat  
