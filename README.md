# Commander  
A terminal. Very barebones, but functional.  
  
## Build instructions  
1. Clone the repository  
`$ git clone https://github.com/jonasjaguar/Commander.git`  
2. Change to the directory  
`$ cd Commander/Commander/`  
3. Generate the Makefile  
`$ qmake ./Commander.pro -spec linux-g++ && /usr/bin/make qmake_all`  
4. Build the software  
`$ make`  
5. Install the software (root permissions required!)  
`$ sudo make install`  
Good! The Software is now built and executable!  

## Requirements  
* QTermWidget
