
#include "keccak.cpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>

namespace filesys = std::filesystem;

bool checkIfFile(std::string filePath)
{
    try {
        // Create a Path object from given path string
        filesys::path pathObj(filePath);
        // Check if path exists and is of a regular file
        if (filesys::exists(pathObj) && filesys::is_regular_file(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return false;
}

int main (int argc, char* argv[]) {

  
  std::string new_hash, prev_hash, temp,h;
  Keccak keccak;
  std::stringstream ss;
  char c;
  


  for ( filesys::recursive_directory_iterator end, dir(argv[1]); 
  dir != end; ++dir ) {

      h = dir->path().string();
      //clear the ss to make sure no other files are left
      ss.clear();
      
      if(checkIfFile(h)){

        //prints out path
        //std::cout<< h <<std::endl;

        //opens file
        std::ifstream in_file(h,std::ios::binary);

        //reads the files as individual characters and writes to stringstream
        while(!in_file.eof()){
        
            in_file >> c;

            ss << c;
          
  
        }//while

        //std::cout<< ss.str() << std::endl;
          
        //produces a keccak256 hash of the contents of ss
        new_hash = keccak(ss.str());

        //appends the new hash to the old hash and hashes
        new_hash = keccak(new_hash + prev_hash);

        //std::cout << new_hash << std::endl;

        prev_hash = new_hash;

          
        in_file.close();

      }//if
  }//for

  std::ofstream out_file("root.txt");
  out_file << new_hash;
  out_file.close();
  return 0;

  
  
}