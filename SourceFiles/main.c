#include "./structures.h"
#include "./functions.h"

int main(){
	INPUT ip; // input event
	Array arr = newArray();
	map mapA = new_map();
	
	setUpKeyboard(&ip); // set up the user's keyboard
	setUpKeys(&arr);
	setUpMap(&mapA);
	
	Sleep(2000);
	
	runThroughText(ip, &arr, &mapA, "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ `~!@#$%^&*()_+1234567890-=|\\[]{};'\\:\"|./>?,<", 0);
	
	return 1;
}