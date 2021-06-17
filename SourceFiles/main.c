#include "./structures.h"
#include "./functions.h"

/* // data injection
        int*data = (int*)malloc(1000);
        int i;
        for(i=0; i<10; i++){
                (*(data+i)) = i;
        }
        printf("%d\n", data[2]);
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
