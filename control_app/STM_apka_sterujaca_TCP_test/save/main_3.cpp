/*
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/joystick.h>
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include <string>

using namespace std;

int read_event(int fd, struct js_event *event)
{
    ssize_t bytes;

    bytes = read(fd, event, sizeof(*event));

    if (bytes == sizeof(*event)){
        return 0;
    } else {
         return -1;
    }
       

}

int main(int argc, char *argv[]){

    js_event joy;
    const char *device;

    if (argc > 1)
        device = argv[1];
    else
        device = "/dev/input/js0";


    int js = open(device, O_RDONLY);
    cout<<js<<endl;

    if(js == -1){
        cout<<"Brak dostępu do joystick'a"<<endl;
    } else {
        cout<<"Kontroler działa poprawnie - milej zabawy !";
       

        while(read_event(js, &joy) == 0){
               
            switch(joy.type){

                case JS_EVENT_BUTTON:
                    cout<<joy.number<<" -> "<<joy.value<<" - "<<joy.type<<endl;
                    break;
                case JS_EVENT_AXIS:
                     cout<<joy.number<<" -> "<<joy.value<<" - "<<joy.type<<endl;
                     //printf("Button %u %s\n", joy.number, joy.value ? "pressed" : "released");
                    break;
                default:
                    break;

            }


        };
    }


}*/

#include <stdio.h>
#include <fcntl.h>

#ifdef linux
#include <linux/joystick.h>
#define JOY_DEV "/dev/js0"
#endif

#ifdef __FREE_BSD_
#include <machine/joystick.h>
#define JOY_DEV "/dev/joy0"
#endif

int main()
{
	int joy_fd;
	struct JS_DATA_TYPE js;

		/* open the joystick */
	if( ( joy_fd = open( JOY_DEV, O_RDONLY ) ) < 0 )
	{
		printf( "Couldn't open joystick device %s\n", JOY_DEV );
		return -1;
	}

	printf( "Here we go, hit ^c to quit\n\n" );

	while( 1 )	/* infinite loop */
	{
			/* read the joystick state into js */
		if( read( joy_fd, &js, JS_RETURN ) != JS_RETURN )
		{
			printf( "\nFailed read\n" );
		}

			/* print the results */
		printf("X: % 4d  Y: % 4d  B1: %1d  B2: %1d  \r"
				,js.x	/* X axis */
				,js.y	/* Y axis */
				,(js.buttons & 1) ? 1 : 0	/* button 1 */
				,(js.buttons & 2) ? 1 : 0 );	/* button 2 */
	}

	close(joy_fd);	/* too bad we never get here */
	return 0;
}