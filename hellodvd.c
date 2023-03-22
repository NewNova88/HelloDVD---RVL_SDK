/*
	This shows how to :
	 - Change directory
	 - Load a simple TXT file
*/

#include <revolution.h>
#include "customOSInit.h"

void main(void)
{
	// The directory and filename we will use
	char* directoryPath = "helloDVD";
	char* fileName = "hello2.txt";
	
	// The DVD file info, file size and pointer to buffer
	DVDFileInfo fileInfo;
	u32 fileSize;
	u8* buffer;
	u8* ptr; // The pointer we're going to use for displaying the file
	u32 i;
	
	// Init the OS (custom) and DVD
	MyCustomOSInit();
	DVDInit();
	
	// We must first change the data directory
	if (FALSE == DVDChangeDir(directoryPath))
	{
		OSHalt("Cannot Change Directory !\n");
	}
	
	// We must open the file before accessing it
	if (FALSE == DVDOpen(fileName, &fileInfo))
	{
		OSHalt("Cannot Open/Access File !\n");
	}
	
	// We get the size of the file
	fileSize = DVDGetLength(&fileInfo);
	
	// We allocate a buffer (32 byte aligned because OSAlloc) to read the file
	buffer = (u8*)OSAlloc(OSRoundUp32B(fileSize));
	
	// We read the entire file, and check if any error occurs
	if (0 >DVDRead(&fileInfo, (void*)buffer, OSRoundUp32B(fileSize), 0))
	{
		OSHalt("Error Occured When Reading File !\n");
	}
	
	// Close the file
	DVDClose(&fileInfo);
	
	// Now we can use the file !
	// Since this is a txt file, let's try to print it !
	OSReport("\n");
	ptr = buffer;
	for(i = 0; i < fileSize; i++)
	{
		OSReport("%c", *ptr++);
	}
	OSReport("\n\n");
	
	
	// Free the buffer
	OSFree(buffer);
	
	OSHalt("This is the end !\n");
}