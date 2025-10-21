// FilenameValidator.cpp
// This is used for checking whether a filename provided is valid or not.
#include <iostream>
#include <string>
#include "../include/FilenameValidator.hpp"

// checks whether a given filename is correct.
bool is_valid(std::string filename)
{
   int i=0;
   int dot_count= 0;
   int len= filename.length();

   while(i<len)
   {
      if(filename[i]=='.')
      {
	if(i==0)
	{
	  return false;
	}
        dot_count++;
	i++;
      }

      if( (  ( filename[i]>='0' && filename[i]<='9') // character must be from the range [0-9]
             || ( filename[i]>='a' && filename[i]<='z') // character must be from the range [a-z]
	        || ( filename[i]>='A' && filename[i]<='Z') // character must be from the range [A-Z]
	           || filename[i]=='_')
	             //|| (filename[i]=='.' && i!=0) 
      )
      {
	//std::cout<<filename[i]<<std::endl;
	i++;
	continue;
      }
      else
      {
        return false;
      }
   }

   if(dot_count!=1)
   {
     return false;
   } 

   return true;
}
