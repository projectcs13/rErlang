#!/bin/bash  
add-apt-repository "deb http://ftp.sunet.se/pub/lang/CRAN/bin/linux/ubuntu precise/" 
apt-get update
apt-get install r-base
wget http://cran.r-project.org/src/contrib/forecast_4.8.tar.gz
R CMD INSTALL forecast_4.8.tar.gz

