#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Input
{
public:

    enum DirectXInputType
    {
        DXI_MOUSE = 0,
        DXI_KEYBOARD = 1
    };

    enum DirectXKeyEvent
    {
        DXE_SYSKEYUP = 0x0105,
        DXE_KEYUP = 0x0101,
        DXE_SYSKEYDOWN = 0x0104,
        DXE_KEYDOWN = 0x0100,
        /*DXE_LBUTTONDBLCLK = 0x0203,
        DXE_LBUTTONUP = 0x0202,
        DXE_LBUTTONDOWN = 0x0201,
        DXE_MBUTTONDBLCLK = 0x0209,
        DXE_MBUTTONUP = 0x0208,
        DXE_MBUTTONDOWN = 0x0207,
        DXE_RBUTTONDBLCLK = 0x0206,
        DXE_RBUTTONUP = 0x0205,
        DXE_RBUTTONDOWN = 0x0204,
        DXE_XBUTTONDBLCLK = 0x020D,
        DXE_XBUTTONUP = 0x020C,
        DXE_XBUTTONDOWN = 0x020B,*/

    };

    enum DirectXKey
    {
        DXK_BACK = 0x08,                //BACKSPACE key
        DXK_TAB = 0x09,                 //TAB key
        DXK_CLEAR = 0x0C,               //CLEAR key
        DXK_RETURN = 0x0D,              //ENTER key
        DXK_SHIFT = 0x10,               //SHIFT key
        DXK_CONTROL = 0x11,             //CTRL key
        DXK_MENU	= 0x12,	            //ALT key
        DXK_PAUSE = 0x13,	            //PAUSE key
        DXK_CAPITAL = 0x14,	            //CAPS LOCK key
        DXK_KANA = 0x15,                //IME Kana mode
        DXK_HANGUEL = 0x15,	            //IME Hanguel mode(maintained for compatibility; use DXK_HANGUL)
        DXK_HANGUL = 0x15,	            //IME Hangul mode
        DXK_IME_ON = 0x16,	            //IME On
        DXK_JUNJA = 0x17,	            //IME Junja mode
        DXK_FINAL = 0x18,	            //IME final mode
        DXK_HANJA = 0x19,	            //IME Hanja mode
        DXK_KANJI = 0x19,	            //IME Kanji mode
        DXK_IME_OFF = 0x1A,	            //IME Off
        DXK_ESCAPE = 0x1B,	            //ESC key
        DXK_CONVERT = 0x1C,	            //IME convert
        DXK_NONCONVERT = 0x1D,	        //IME nonconvert
        DXK_ACCEPT = 0x1E,	            //IME accept
        DXK_MODECHANGE = 0x1F,	        //IME mode change request
        DXK_SPACE = 0x20,	            //SPACEBAR
        DXK_PRIOR = 0x21,	            //PAGE UP key
        DXK_NEXT = 0x22,	            //PAGE DOWN key
        DXK_END = 0x23,	                //END key
        DXK_HOME = 0x24,	            //HOME key
        DXK_LEFT = 0x25,	            //LEFT ARROW key
        DXK_UP = 0x26,	                //UP ARROW key
        DXK_RIGHT = 0x27,	            //RIGHT ARROW key
        DXK_DOWN = 0x28,	            //DOWN ARROW key
        DXK_SELECT = 0x29,              //SELECT key
        DXK_PRINT = 0x2A,	            //PRINT key
        DXK_EXECUTE = 0x2B,	            //EXECUTE key
        DXK_SNAPSHOT = 0x2C,	        //PRINT SCREEN key
        DXK_INSERT = 0x2D,	            //INS key
        DXK_DELETE = 0x2E,	            //DEL key
        DXK_HELP = 0x2F,	            //HELP key
        DXK_0 = 0x30,	                //0 key
        DXK_1 = 0x31,	                //1 key
        DXK_2 = 0x32,	                //2 key
        DXK_3 = 0x33,	                //3 key
        DXK_4 = 0x34,	                //4 key
        DXK_5 = 0x35,	                //5 key
        DXK_6 = 0x36,	                //6 key
        DXK_7 = 0x37,	                //7 key
        DXK_8 = 0x38,	                //8 key
        DXK_9 = 0x39,	                //9 key
        DXK_A = 0x41,	                //A key
        DXK_B = 0x42,	                //B key
        DXK_C = 0x43,	                //C key
        DXK_D = 0x44,	                //D key
        DXK_E = 0x45,	                //E key
        DXK_F = 0x46,	                //F key
        DXK_G = 0x47,	                //G key
        DXK_H = 0x48,	                //H key
        DXK_I = 0x49,	                //I key
        DXK_J = 0x4A,	                //J key
        DXK_K = 0x4B,	                //K key
        DXK_L = 0x4C,	                //L key
        DXK_M = 0x4D,	                //M key
        DXK_N = 0x4E,	                //N key
        DXK_O = 0x4F,	                //O key
        DXK_P = 0x50,	                //P key
        DXK_Q = 0x51,	                //Q key
        DXK_R = 0x52,	                //R key
        DXK_S = 0x53,	                //S key
        DXK_T = 0x54,	                //T key
        DXK_U = 0x55,	                //U key
        DXK_V = 0x56,	                //V key
        DXK_W = 0x57,	                //W key
        DXK_X = 0x58,	                //X key
        DXK_Y = 0x59,	                //Y key
        DXK_Z = 0x5A,	                //Z key
        DXK_LWIN = 0x5B,	            //Left Windows key(Natural keyboard)
        DXK_RWIN = 0x5C,	            //Right Windows key(Natural keyboard)
        DXK_APPS = 0x5D,	            //Applications key(Natural keyboard)
        DXK_SLEEP = 0x5F,	            //Computer Sleep key
        DXK_NUMPAD0 = 0x60,	            //Numeric keypad 0 key
        DXK_NUMPAD1	= 0x61,	            //Numeric keypad 1 key
        DXK_NUMPAD2	= 0x62,	            //Numeric keypad 2 key
        DXK_NUMPAD3	= 0x63,	            //Numeric keypad 3 key
        DXK_NUMPAD4	= 0x64,	            //Numeric keypad 4 key
        DXK_NUMPAD5	= 0x65,	            //Numeric keypad 5 key
        DXK_NUMPAD6	= 0x66,	            //Numeric keypad 6 key
        DXK_NUMPAD7	= 0x67,	            //Numeric keypad 7 key
        DXK_NUMPAD8	= 0x68,	            //Numeric keypad 8 key
        DXK_NUMPAD9	= 0x69,	            //Numeric keypad 9 key
        DXK_MULTIPLY = 0x6A,	        //Multiply key
        DXK_ADD	= 0x6B,	                //Add key
        DXK_SEPARATOR = 0x6C,	        //Separator key
        DXK_SUBTRACT = 0x6D,	        //Subtract key
        DXK_DECIMAL	= 0x6E,	            //Decimal key
        DXK_DIVIDE = 0x6F,	            //Divide key
        DXK_F1 = 0x70,	                //F1 key
        DXK_F2 = 0x71,	                //F2 key
        DXK_F3 = 0x72,	                //F3 key
        DXK_F4 = 0x73,	                //F4 key
        DXK_F5 = 0x74,	                //F5 key
        DXK_F6 = 0x75,	                //F6 key
        DXK_F7 = 0x76,	                //F7 key
        DXK_F8 = 0x77,	                //F8 key
        DXK_F9 = 0x78,	                //F9 key
        DXK_F10 = 0x79,	                //F10 key
        DXK_F11 = 0x7A,	                //F11 key
        DXK_F12	= 0x7B,	                //F12 key
        DXK_F13	= 0x7C,	                //F13 key
        DXK_F14	= 0x7D,	                //F14 key
        DXK_F15	= 0x7E,	                //F15 key
        DXK_F16	= 0x7F,	                //F16 key
        DXK_F17	= 0x80,	                //F17 key
        DXK_F18	= 0x81,	                //F18 key
        DXK_F19	= 0x82,	                //F19 key
        DXK_F20	= 0x83,	                //F20 key
        DXK_F21	= 0x84,	                //F21 key
        DXK_F22	= 0x85,	                //F22 key
        DXK_F23	= 0x86,	                //F23 key
        DXK_F24	= 0x87,	                //F24 key
        DXK_NUMLOCK	= 0x90,	            //NUM LOCK key
        DXK_SCROLL = 0x91,	            //SCROLL LOCK key
        DXK_LSHIFT = 0xA0,	            //Left SHIFT key
        DXK_RSHIFT = 0xA1,	            //Right SHIFT key
        DXK_LCONTROL = 0xA2,	        //Left CONTROL key
        DXK_RCONTROL = 0xA3,	        //Right CONTROL key
        DXK_LMENU = 0xA4,	            //Left ALT key
        DXK_RMENU = 0xA5,	            //Right ALT key
        DXK_BROWSER_BACK = 0xA6,	    //Browser Back key
        DXK_BROWSER_FORWARD	= 0xA7,	    //Browser Forward key
        DXK_BROWSER_REFRESH = 0xA8,	    //Browser Refresh key
        DXK_BROWSER_STOP = 0xA9, 	    //Browser Stop key
        DXK_BROWSER_SEARCH = 0xAA,	    //Browser Search key
        DXK_BROWSER_FAVORITES = 0xAB,	//Browser Favorites key
        DXK_BROWSER_HOME = 0xAC,	    //Browser Start and Home key
        DXK_VOLUME_MUTE = 0xAD, 	    //Volume Mute key
        DXK_VOLUME_DOWN = 0xAE,	        //Volume Down key
        DXK_VOLUME_UP = 0xAF,	        //Volume Up key
        DXK_MEDIA_NEXT_TRACK = 0xB0,	//Next Track key
        DXK_MEDIA_PREV_TRACK = 0xB1,	//Previous Track key
        DXK_MEDIA_STOP = 0xB2,	        //Stop Media key
        DXK_MEDIA_PLAY_PAUSE = 0xB3,	//Play / Pause Media key
        DXK_LAUNCH_MAIL = 0xB4,	        //Start Mail key
        DXK_LAUNCH_MEDIA_SELECT = 0xB5,	//Select Media key
        DXK_LAUNCH_APP1 = 0xB6,	        //Start Application 1 key
        DXK_LAUNCH_APP2 = 0xB7,	        //Start Application 2 key
        DXK_OEM_1 = 0xBA,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ';:' key
        DXK_OEM_PLUS = 0xBB,	        //For any country / region, the '+' key
        DXK_OEM_COMMA = 0xBC,	        //For any country / region, the ',' key
        DXK_OEM_MINUS = 0xBD,	        //For any country / region, the '-' key
        DXK_OEM_PERIOD = 0xBE,	        //For any country / region, the '.' key
        DXK_OEM_2 = 0xBF,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '/?' key
        DXK_OEM_3 = 0xC0,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '`~' key
        DXK_OEM_4 = 0xDB,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '[{' key
        DXK_OEM_5 = 0xDC,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '\|' key
        DXK_OEM_6 = 0xDD,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ']}' key
        DXK_OEM_7 = 0xDE,	            //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the 'single-quote/double-quote' key
        DXK_OEM_8 = 0xDF,	            //Used for miscellaneous characters; it can vary by keyboard.
        DXK_OEM_102	= 0xE2,	            //The <> keys on the US standard keyboard, or the \\ | key on the non - US 102 - key keyboard
        DXK_PROCESSKEY = 0xE5,	        //IME PROCESS key
        DXK_PACKET = 0xE7,	            //Used to pass Unicode characters as if they were keystrokes.The DXK_PACKET key is the low word of a 32 - bit Virtual Key value used for non - keyboard input methods.For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
        DXK_ATTN = 0xF6,	            //Attn key
        DXK_CRSEL = 0xF7,	            //CrSel key
        DXK_EXSEL = 0xF8,	            //ExSel key
        DXK_EREOF = 0xF9,	            //Erase EOF key
        DXK_PLAY = 0xFA,	            //Play key
        DXK_ZOOM = 0xFB,	            //Zoom key
        DXK_NONAME = 0xFC,	            //Reserved
        DXK_PA1	= 0xFD,	                //PA1 key
        DXK_OEM_CLEAR = 0xFE,	        //Clear key

        DXK_LEFTMOUSEBUTTON = 0x01,     //Left mouse button
        DXK_RIGHTMOUSEBUTTON	= 0x02, //Right mouse button
        DXK_CANCEL = 0x03,              //Control-break processing
        DXK_MIDDLEWHEELBUTTON	= 0x04, //Middle mouse button (three-button mouse)
        DXK_MOUSEBUTTON3 = 0x06,        //X1 mouse button
        DXK_MOUSEBUTTON4 = 0x05,        //X2 mouse button
    };
};
