#! /bin/bash

# # --- THE SERVER ---

# sonar.sh console

# # --- THE CLIENT ---

# build-wrapper-linux-x86-64 --out-dir build_wrapper_output_directory make clean all

# sonar-scanner \
#   -Dsonar.projectKey=tis-compelysis \
#   -Dsonar.sources=. \
#   -Dsonar.cfamily.build-wrapper-output=build_wrapper_output_directory \
#   -Dsonar.host.url=http://localhost:9000 \
#   -Dsonar.login=d73f9bfefb51b305cd7ef984c6ac0db2f0c0de3b

# --- NEW ---

export SONAR_TOKEN=XXX

# build-wrapper-linux-x86-64 --out-dir bw-output <insert_your_clean_build_command>
build-wrapper-linux-x86-64 --out-dir bw-output make clean all

sonar-scanner \
  -Dsonar.organization=jakub-zwolakowski \
  -Dsonar.projectKey=jakub-zwolakowski_tis-compelysis \
  -Dsonar.sources=. \
  -Dsonar.cfamily.build-wrapper-output=bw-output \
  -Dsonar.host.url=https://sonarcloud.io
