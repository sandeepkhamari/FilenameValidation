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
}
