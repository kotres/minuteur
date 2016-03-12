#include "functions_test.h"

//test of function in time_type.c

void test_of_time_type(void)
{
  printf("test of time_type_valid\n");
  time_type_t type=second;
  if(time_type_valid(type)==0)
    printf("second KO\n");
  type=minute;
  if(time_type_valid(type)==0)
    printf("minute KO\n");
  type=hour;
  if(time_type_valid(type)==0)
    printf("hour KO\n");
  int i=3;
  for(i=3;i<20;i++){
    if(time_type_valid(i)==1)
      printf("%d KO\n",i);
  }
}

void test_of_input(void)
{
	printf("test of input\n");
	printf("test of input_initialize\n");
	input_t input;
	input_t *ptr=&input;
	input_initialize(ptr);
	if(ptr->interrupt_buffer!=0)
		printf("input_initialize interrupt_buffer KO\n");
	if(ptr->flags.flag_byte!=0)
		printf("input_initialize flags KO\n");
	printf("test of input_valid\n");
	if(input_valid(ptr)==0)
		printf("input_valid false negative\n");
	ptr->flags.no_flags=5;
	if(input_valid(ptr)==1)
		printf("input_valid false positive\n");
	input_initialize(ptr);
	//buttons
	printf("test of input_update\n");
	RA2=0;
	RA3=0;
	input_update(ptr);
	if(ptr->flags.menu_button_state==NOT_SET)
		printf("input_update menu_button_state KO\n");
	if(ptr->flags.pause_button_state==NOT_SET)
		printf("inpt_update menu_pause_state KO\n");
	if(ptr->flags.menu_button_ignore==NOT_SET)
		printf("input_update menu_button_ignre KO\n");
	if(ptr->flags.pause_button_ignore==NOT_SET)
		printf("input_update pause_button_ignore KO\n");
	input_update(ptr);
	if(ptr->flags.menu_button_state==SET)
		printf("input_update menu_button_state KO\n");
	if(ptr->flags.pause_button_state==SET)
		printf("inpt_update menu_pause_state KO\n");
	if(ptr->flags.menu_button_ignore==NOT_SET)
		printf("input_update menu_button_ignre KO\n");
	if(ptr->flags.pause_button_ignore==NOT_SET)
		printf("input_update pause_button_ignore KO\n");
	RA2=1;
	RA3=1;
	input_update(ptr);
	if(ptr->flags.menu_button_state==SET)
		printf("input_update menu_button_state KO\n");
	if(ptr->flags.pause_button_state==SET)
		printf("inpt_update menu_pause_state KO\n");
	if(ptr->flags.menu_button_ignore==SET)
		printf("input_update menu_button_ignre KO\n");
	if(ptr->flags.pause_button_ignore==SET)
		printf("input_update pause_button_ignore KO\n");
}


//test function
void test_function(void)
{
    test_of_time_type();
    test_of_input();
}
