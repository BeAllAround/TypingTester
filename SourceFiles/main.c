#include "./structures.h"
#include "./functions.h"

/* // data injection
        int i, *data = (int*)malloc(1000);
        for(i=0; i<10; i++){
                (*(data+i)) = i; // rvalue
        }
*/

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
