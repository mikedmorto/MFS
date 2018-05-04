#!/bin/bash
cp ../../build/mfs_fsd/fsd . && ./fsd --docroot . --https-address 0.0.0.0 --https-port 8899 --ssl-certificat ssl/server.crt --ssl-private-key ssl/server.key --ssl-tmp-dh ssl/dhp.pem -c config_test.xml
