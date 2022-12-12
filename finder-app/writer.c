#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
	openlog("writer_log", 0, LOG_USER);
        syslog(LOG_INFO, "Writer app initialized");
	
	if( argc != 3 ) {
		printf("Too few arguments supplied\nMust supply a valid PAth with filename and a string to write\n");
		syslog(LOG_ERR, "Error: Too few arguments supplied");
		return 1;
	}

	
 	

	FILE * file_pointer = fopen(argv[1], "w");
	if(file_pointer == NULL)
	{
		syslog(LOG_ERR, "Error: Could not open file");
		closelog();
		printf("Error: Could not open file\n");
		return 1;
	}

	
	if(fprintf(file_pointer, argv[2]) < 0)
	{
		printf("Error while writing to the file\n");
		syslog(LOG_ERR, "Error: Could not write to file");
		closelog();
		return 1;
	} 
	else
	{
		syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	}

   
        if(fclose(file_pointer) != 0)
	{
		printf("Error while closing to the file\n");
		syslog(LOG_ERR, "Error: Could not close file");
		closelog();
		return 1;
	}

	syslog(LOG_INFO, "Writer app finish successfully");
	closelog();
	return 0;
}
