#include"../include/common/data.h"
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	 static uint8_t result[15];
	 	ptr = &result;
	 	uint8_t length=0;
	 	int32_t tmp, absV;
	 	uint8_t * temp_ptr;
	 	temp_ptr=ptr;

	 	if (base<2||base>16){
	 		printf("error");
	 		return -1;
	 	}
	 	absV = abs(data);
	 	        if(data<0 && base==10)
	 	        {
	 	            //data*=(-1);
	 				*ptr='-';
	 	            length++;
	 	            ptr++;
	 	        }

	 	        for(tmp=absV;tmp>0;tmp/=base,ptr++);
	 	        *ptr='\0';
	 	        ptr--;
	 	        for(tmp=absV;tmp>0;tmp/=base,ptr--)
	 	        {

	 	           *ptr=tmp%base+'0';
	 	            length++;
	 	        }
	 	        ptr = temp_ptr;
	 	        while(*ptr!='\0'){
	 	        	printf("%c",*ptr);
	 	        	ptr++;
	 	        }

	 return length;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t res=0;
	uint8_t *temp_ptr;
	int8_t sign=1;
	temp_ptr=ptr;
	

	if(base<2 || base>16){
		return -1;
	}

	if(*temp_ptr == '-' && base==10){
		temp_ptr++;
		sign=-1;
	}
	//temp_ptr++;
	while(*temp_ptr !='\0'){
		if (*temp_ptr>64){
			res=res*base+(*temp_ptr-'A'+10);
		}
		else{
		res=res*base+(*temp_ptr-'0');
		}
		temp_ptr++;
	}


	return sign*res;
}

