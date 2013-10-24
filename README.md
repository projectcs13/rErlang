rErlang
=======

To get rErlang running and install R, follow these instructions:

Run install.sh with sudo rights, this will download and install R.

$  sudo install.sh

Now you need to install the forecast package in R. This is done
by starting R using the command 'R' and running the function 
'install.packages'. You may be prompted with a question, just
press 'Y'.

$ R
> install.packages("forecast")
> q()
$

Now you are ready to compile rErlang! Write 'make'!

$ make

After this step, you are done! Yay!
