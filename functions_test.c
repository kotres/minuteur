#include "functions_test.h"

//test of function in time_type.c

void test_of_time_type(void)
{
  printf("test of time_type_valid\n");
  time_type type=second;
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

void test_of_flag_array(void)
{
    printf("test of flag_array_initialize\n");
    flag_array_t array;
    flag_array_initialise(&array);
    if(flag_array_valid(&array)==0)
        printf("flag_array_initialize KO\n");
    printf("test of flag_array_valid\n");
    array.flags_number=10;
    if(flag_array_valid(&array)==0)
        printf("flag_array_valid KO\n");
    printf("test of flag_array_set_numbers\n");
    flag_array_set_numbers(&array,4);
    if(array.flags_number!=4)
        printf("flag_array_set_numbers KO\n");
    printf("test of flag_array_set_flag\n");
    flag_array_set_flag(&array,NOT_SET,1);
    if(array.flags.b1!=0)
        printf("flag_array_set_flag KO\n");
    printf("test of flag_array_get_flag_state\n");
    if(flag_array_get_flag_state(&array,1)!=array.flags.b1)
        printf("flag_array_get_flag_state KO\n");
    
}

//test function
void test_function(void)
{
    test_of_time_type();
    test_of_flag_array();
}
