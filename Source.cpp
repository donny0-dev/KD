#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

void movemouse( double x, double y ) {
	SetCursorPos( x, y );
}

void mouseclick( ) {
	INPUT input { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput( 1, &input, sizeof( INPUT ) );
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput( 1, &input, sizeof( INPUT ) );
}

int main( ) {
	static bool mainmenu = false;
	static bool deathmenu = false;
	static bool idle = false;
	static int roundnumber = 0;
	static bool force_restart = false;

	std::stringstream ss;

	while ( true ) {
		HDC getdeathmenudc = GetDC( NULL );
		COLORREF deathmenucolor = RGB( 255, 255, 255 );
		COLORREF getdeathmenucolor = GetPixel( getdeathmenudc, 955, 53 );

		HDC mainmenudc = GetDC( NULL );
		COLORREF mainmenucolor = RGB( 159, 157, 144 );
		COLORREF getmainmenucolor = GetPixel( mainmenudc, 141, 1071 );

		switch ( rand( ) % 2 ) {
		case 0:
			COLORREF deathmenucolor = RGB( 255, 255, 255 );
			COLORREF getdeathmenucolor = GetPixel( getdeathmenudc, 955, 53 );
			COLORREF mainmenucolor = RGB( 159, 157, 144 );
			COLORREF getmainmenucolor = GetPixel( mainmenudc, 141, 1071 );
			//print::set_text("[DEBUG] re_init_pos \n", White);
			Sleep( 2500 );
			break;
		}


		if ( ( getdeathmenucolor == deathmenucolor ) || ( deathmenu == true && mainmenu == false && !idle ) ) {
			deathmenu = true;
			mainmenu = false;
			//idle = false;

			//print::set_text("[DEBUG] death_screen active \n", White);
			//print::set_text("[DEBUG] returning to main_screen \n", White);

			movemouse( 967, 1035 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 869, 591 );
			Sleep( 25 );
			mouseclick( );

			roundnumber++;
		} else {
			deathmenu = false;
			//mainmenu = true;
		}

		if ( ( getmainmenucolor == mainmenucolor ) || ( deathmenu == false && mainmenu == true && !idle ) ) {
			deathmenu = false;
			mainmenu = true;

			//print::set_text("[DEBUG] main_screen active \n", White);
			//print::set_text("[DEBUG] starting a match \n", White);

			movemouse( 961, 641 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 1187, 275 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 961, 641 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 959, 943 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 739, 441 );
			Sleep( 25 );
			mouseclick( );

			Sleep( 25 );

			movemouse( 1239, 1011 );
			Sleep( 25 );
			mouseclick( );
		} else {
			//deathmenu = true;
			mainmenu = false;
		}

		if ( mainmenu == true ) {
			//ss << "[DEBUG] rounds since start " << roundnumber << "\n";
			//print::set_text(ss.str().c_str(), White);
		}

		if ( getdeathmenucolor != deathmenucolor || getmainmenucolor != mainmenucolor ) {
			mainmenu = false;
			deathmenu = false;
			idle = true;
		}

		Sleep( 50 );
	}

	return NULL;
}