// FilenameValidator.cpp
// This is used for checking whether a filename provided is valid or not.
#include <iostream>
#include <string>
#include "../include/FilenameValidator.hpp"
#include <regex>

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

bool is_valid_regex(std::string filename)
{
  bool result= false;
  try
  {
    //std::regex filename_pattern("^[^.][a-zA-Z0-9_][a-zA-Z0-9_]*[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$"); 
    std::regex filename_pattern("[a-zA-Z0-9_]+\\.[a-zA-Z]+$"); 
    //std::regex filename_pattern("^[a-zA-Z0-9_.-]+$");
    result= std::regex_match(filename, filename_pattern); 
  }
  catch(const std::regex_error& e)
  {
    std::cerr<<" Regex error: "<<e.what()<<std::endl;
    return false;
  }
  return result;
}
