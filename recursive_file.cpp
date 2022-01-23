#include "boost/filesystem.hpp"
#include "keccak.cpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

namespace filesys = boost::filesystem;

bool checkIfDirectory(std::string filePath)
{
    try {
        // Create a Path object from given path string
        filesys::path pathObj(filePath);
        // Check if path exists and is of a directory file
        if (filesys::exists(pathObj) && filesys::is_directory(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return false;
}

int main () {

  
  std::string h;
  std::string new_hash;
  std::string prev_hash;
  std::string temp;
  Keccak keccak;


  for ( filesys::recursive_directory_iterator end, dir("/home/theo/file_test"); dir != end; ++dir ) {
      h = dir->path().string();
      temp.clear();

      if(!checkIfDirectory(h)){

          std::cout<< h <<std::endl;
          std::ifstream in_file(h);

          while(!in_file.eof()){
        
            in_file >> temp;
          
  
          }//while
          new_hash = keccak(temp);
          new_hash = keccak(new_hash + prev_hash);

          std::cout << new_hash << std::endl;

          prev_hash = new_hash;

          in_file.close();

      }//if

      else{
        continue;
      }//else
      
      

  }//for

  std::ofstream out_file("root.txt");
  out_file << new_hash;
  out_file.close();

  
  
}