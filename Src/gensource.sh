#!/bin/sh
thrift --gen cpp Person.thrift
thrift --gen java Person.thrift
thrift --gen php Person.thrift

