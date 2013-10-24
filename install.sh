#!/bin/bash  
sudo add-apt-repository "deb http://ftp.sunet.se/pub/lang/CRAN/bin/linux/ubuntu precise/" 
sudo apt-get update
sudo apt-get install r-base
sudo wget http://cran.r-project.org/src/contrib/forecast_4.8.tar.gz
sudo R CMD INSTALL forecast_4.8.tar.gz

