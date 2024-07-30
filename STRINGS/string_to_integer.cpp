class Solution {
   
public:
   bool isDigit(char ch){    //here we check if it is digit 
    return ch >= '0' && ch <= '9';
  }
    int myAtoi(string s) {
     const int len = s.size();

    if(len == 0){
        return 0;
    }

    int index = 0;

    // skipping white spaces
    while(index < len && s[index] == ' '){ //if it is empty space then we will increase the index
        ++index;
    }
     int result = 0;
    // to handle sign cases
    bool isNegative = false;   //if it is negative then we will make it false

    if(index < len){   
                     
      if(s[index] == '-'){ //if it is negative then we will make it true as negative
        isNegative = true;
        ++index;
      } else if (s[index] == '+'){
          ++index;
      }
    } 
      
      while(index < len && isDigit(s[index])){ //if it is digit and less than length
      int digit = s[index] - '0';   

      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){  //here if it is greater than 32 bit or eaual to 32 bit as well digitw>7
          return isNegative ? INT_MIN : INT_MAX;
      }

      result = (result * 10) + digit; 

      ++index;
    }   
    return isNegative ? -result : result
    }
};