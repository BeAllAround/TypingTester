Key indexArr(Array*arr, int inx){
	return arr->data[inx];
}

Map indexMap(map*m, int inx){
	return m->data[inx];
}
void push(Array*arr, Key item){
	arr->data[arr->length++] = item;
}

void append(map*m, Map item){
	m->data[m->length++] = item;
}

int keySearch(Array*keys, char toFind){
	int i;
	for(i=0; i<keys->length; i++){
		if(indexArr(keys, i).hF == toFind){
			return indexArr(keys, i).iF;
		}
	}
	return -1; // JavaScript raising exception! - keep in mind that we must write a condition while doing up GUI!
}

void setUpKeys(Array*arr){
	char i;
	for(i = 48; i < 58; ++i){ // the range from 0 to z;
		push(arr, newKey((char)i, (int)i));
	}
	for(i = 65; i<91; ++i){
		push(arr, newKey(tolower((char)i), (int)i));
	}
	push(arr, newKey(' ', 0x20));
	push(arr, newKey('.', 0xBE));
	push(arr, newKey(',', 188));
	push(arr, newKey('-', 0xBD));
	push(arr, newKey('/', 0xBF));
	push(arr, newKey(';', 0xBA));
	push(arr, newKey('=', 0xBB));
	push(arr, newKey('`', 0xC0));
	push(arr, newKey('[', 0xDB));
	push(arr, newKey(']', 0xDD));
	push(arr, newKey('\\', 0xDC));
	push(arr, newKey('\'', 0xDE));
}

void setUpMap(map*_map){
	append(_map, newMap('{', '['));
	append(_map, newMap('}', ']'));
	append(_map, newMap('<', ','));
	append(_map, newMap('>', '.'));
	append(_map, newMap('?', '/'));
	append(_map, newMap('|', '\\'));
	append(_map, newMap('!', '1'));
	append(_map, newMap('@', '2'));
	append(_map, newMap('#', '3'));
	append(_map, newMap('$', '4'));
	append(_map, newMap('%', '5'));
	append(_map, newMap('^', '6'));
	append(_map, newMap('&', '7'));
	append(_map, newMap('*', '8'));
	append(_map, newMap('(', '9'));
	append(_map, newMap(')', '0'));
	append(_map, newMap('_', '-'));
	append(_map, newMap('"', '\''));
	append(_map, newMap('+', '='));
	append(_map, newMap(':', ';'));
	append(_map, newMap('~', '`'));
}

int runner(INPUT*ip, Array*keys, map*mapA, char toFind){
	int b = 0;
	char c;
	int i;
	for(i=0; i<mapA->length; i++){
		if(toFind==indexMap(mapA, i).first){
			c = indexMap(mapA, i).second;
			b = 1;
			break;
		}
		b = 0;
	}
	if(!b)return -1;
	
	ip->ki.wVk = 0x10; 
	ip->ki.dwFlags = 0; 
	SendInput(1, ip, sizeof(INPUT));
	pressAndRelease(*ip, keySearch(keys, c), 0);
	// Release the key
	ip->ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, ip, sizeof(INPUT));
	return 1;
}

//////////////////////////////////////////////////////////////////////
int countWords(char*text){
	int i, c = 1;
	for(i=0; i<strlen(text); i++){
		if(text[i]==' ' || text[i]=='\n' || text[i]=='\t'){
			c++;
			if(text[i+1] == ' ')c--;
		}
	}
	return c;
}

int calculateSpeed(int length, int speed){
	int Inner = length * 60;
	double Outer = round((double)(Inner/speed));
	double Outer2 = round(Outer/5);
	return round((double)(Outer2/length)*1000);
}
//////////////////////////////////////////////////////////////////////

void runThroughText(INPUT ip, Array*keys, map*mapA, char*text, int speed){ // int runner(INPUT*ip, Array*keys, map*mapA, char toFind){
	// CALCULATE THE SPEED!!!
	int counted = countWords(text);
	
	int inx, i;
	for(i=0; i<strlen(text); i++){
		inx = keySearch(keys, tolower(text[i]));
		printf("%d ", inx);
		if(inx!=-1)pressAndRelease(ip, inx, isupper(text[i]));
		else runner(&ip, keys, mapA, text[i]);
		Sleep(speed); // Sleep(calculateSpeed(strlen(text), speed));
	}
}

void CapsLock(INPUT ip){
	pressAndRelease(ip, 0x14, 0);
}

void pressAndRelease(INPUT ip, int VKey, int UpperCase){
	if(UpperCase){
		CapsLock(ip);
	}
	// Press the "A" key
	ip.ki.wVk = VKey; // virtual-key code for the "a" key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the "A" key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
	if(UpperCase){ // turn off;
		CapsLock(ip);
	}
}

void setUpKeyboard(INPUT* ip){
	// Set up a generic keyboard event.
	ip->type = INPUT_KEYBOARD;
	ip->ki.wScan = 0; // hardware scan code for key
	ip->ki.time = 0;
	ip->ki.dwExtraInfo = 0;
}
