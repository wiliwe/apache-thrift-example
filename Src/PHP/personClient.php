<?php

namespace IDV;
error_reporting(E_ALL);

require_once __DIR__ . '/thrift/Thrift/ClassLoader/ThriftClassLoader.php';
require_once __DIR__ . '/thrift/IDV/PersonService.php';
require_once __DIR__ . '/thrift/IDV/Types.php';

use Thrift\ClassLoader\ThriftClassLoader;
use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\TBufferedTransport;

// Load
$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', __DIR__ . '/thrift');
$loader->registerDefinition('IDV', __DIR__ . '/thrift/IDV');
$loader->register();

// Init
$server = '127.0.0.1';
$port = 8989;
$socket = new TSocket($server, $port);
$transport = new TBufferedTransport($socket, 1024, 1024);
$protocol = new TBinaryProtocol($transport);
$client = new PersonServiceClient($protocol);

// Config
$socket->setSendTimeout(30 * 1000);
$socket->setRecvTimeout(30 * 1000);

// Connect
$transport->open();

// Call...
$response = $client->getPersonById(125);

// Print response...
var_dump($response);

// Close
$transport->close();
