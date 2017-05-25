#include "contiki.h"
#include "contiki-net.h"
#include "rest-engine.h"

#define MAX_VALVE 100
#define MIN_VALVE 0

static int current_status;


void get_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	/* Populat the buffer with the response payload*/
	char message[10];
	int length = 10;

	sprintf(message,"status:%03d",current_status);

	length = strlen(message);
	memcpy(buffer, message, length);

	REST.set_header_content_type(response, REST.type.TEXT_PLAIN); 
	REST.set_header_etag(response, (uint8_t *) &length, 1);
	REST.set_response_payload(response, buffer, length);
}

void post_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{

  int len;
  const char *val = NULL;
     
  len=REST.get_post_variable(request, "status", &val);
     
  if( len > 0 ){
     current_status = atoi(val);	

     REST.set_response_status(response, REST.status.CREATED);
  } else {
     REST.set_response_status(response, REST.status.BAD_REQUEST);
  }
}

RESOURCE(oxigenMaskValve, "title=\"Oxigen Valve\";rt=\"Percentage\";if=\"Actuator\"", get_handler, post_handler, NULL, NULL);

PROCESS(oxigenMaskValve_main, "Oxigen Valve Main");

AUTOSTART_PROCESSES(&oxigenMaskValve_main);

PROCESS_THREAD(oxigenMaskValve_main, ev, data){
	PROCESS_BEGIN();

	rest_init_engine();

	rest_activate_resource(&oxigenMaskValve, "Oxigen Valve");



	while(1) 
	{
   		PROCESS_WAIT_EVENT();
	}

	PROCESS_END();
}