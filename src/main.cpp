#include "../include/FilenameValidator.hpp"

int main()
{
   std::string filename= "sandeep.txt";
   if(is_valid(filename))
   {
      std::cout<<filename<<" is valid."<<std::endl;
   }
   else
   {
      std::cout<<filename<<" is not valid."<<std::endl;
   }

   if(is_valid_regex(filename))
   {
      std::cout<<filename<<" is valid."<<std::endl;
   }
   else
   {
      std::cout<<filename<<" is not valid."<<std::endl;
   }

   std::string invalid_string= "san?deep.txt";
   if(is_valid_regex(invalid_string))
   {
      std::cout<<invalid_string<<" is valid."<<std::endl;
   }
   else
   {
      std::cout<<invalid_string<<" is not valid."<<std::endl;
   }  
}
