#!/bin/bash

echo "Uploading a Project Build to Coverity Scan"

echo "1. Clean the project -- make clean, rm cov-int"
make clean
rm -rf cov-int

echo "2. Build -- cov-build --dir cov-int make"
cov-build --dir cov-int make all

echo "3. Compress -- tar czvf myproject.tgz cov-int"
tar czvf myproject.tgz cov-int

echo "4. Send -- curl"
curl --form token=xA5J5w1KFPbtwMrhh66nNA \
  --form email=jakub.zwolakowski@trust-in-soft.com \
  --form file=@/home/qba/git/tis-compelysis/myproject.tgz \
  --form version="Version42" \
  --form description="Description42" \
  https://scan.coverity.com/builds?project=jakub-zwolakowski%2Ftis-compelysis

echo "5. Done!"
