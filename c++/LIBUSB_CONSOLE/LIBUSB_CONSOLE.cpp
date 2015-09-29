// LIBUSB_CONSOLE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define VID    0x072F
#define PID    0x90D5
//#define VID    0x0951
//#define PID    0x168e
static void print_devs(libusb_device **devs)
{
	libusb_device *dev;
	int i = 0, j = 0;
	uint8_t path[8]; 

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor\n");
			return;
		}

		if(desc.idVendor==VID&&desc.idProduct==PID)
		{
			struct libusb_device_handle *handle;
			r=libusb_open(dev,&handle);
			if (r < 0) 
			{
				fprintf(stderr, "failed to open failure\n");
				return;
			}else
			{
				fprintf(stderr, "open my device success\n");
			}
			r=libusb_claim_interface(handle,0);
			if (r < 0) 
			{
				fprintf(stderr, "failed to claim interface\n");
				return;
			}else
			{
				fprintf(stderr, "claimed interface\n");
			}
			//r=libusb_release_interface(handle,0);
			libusb_close(handle);
		}
//		struct libusb_config_descriptor *config;
//		r=libusb_get_config_descriptor(dev,0,&config);
//		if (r < 0) {
//			fprintf(stderr, "failed to get device config descriptor\n");
//			return;
//		}

//		printf("%04x:%04x (bus %d, device %d)",
//			desc.idVendor, desc.idProduct,
//			libusb_get_bus_number(dev), libusb_get_device_address(dev));
//
//		r = libusb_get_port_numbers(dev, path, sizeof(path));
//		if (r > 0) {
//			printf(" path: %d", path[0]);
//			for (j = 1; j < r; j++)
//				printf(".%d", path[j]);
//		}
	}
}


int main(int argc, char* argv[])
{
	libusb_device **devs;
	int r;
	ssize_t cnt;

	r = libusb_init(NULL);
	if (r < 0)
		return r;

	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0)
		return (int) cnt;

	libusb_device_handle *dev;
	dev=libusb_open_device_with_vid_pid(NULL,VID,PID);
	r=libusb_set_configuration(dev,0);
	r=libusb_claim_interface(dev,0);
	if(r==0)
		printf("claimed interface\n");
	r=libusb_detach_kernel_driver(dev,0);
	if(r==0)
		printf("detached kernel\n");
	unsigned char data[10]={0};
	int actual_length;
	for(int i=0x00;i<0xff;i++)
	{
		r=libusb_interrupt_transfer(dev,i,data,10,&actual_length,0);
		if(r<0)
		{
			printf("send date failure,%d\n",r);
		}
	}
	//print_devs(devs);
	libusb_release_interface(dev,0);
	libusb_close(dev);
	libusb_free_device_list(devs, 1);

	libusb_exit(NULL);
	return 0;
}

