# 🤖 Minitalk - 42 Project

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

Minitalk is a 42 school project focused on inter-process communication (IPC) using UNIX signals. The goal is to build a client-server program where the client sends messages to the server, which the server displays in real-time.

## 📑 Table of Contents
- [📖 Overview](#overview)
- [🎯 Objectives](#objectives)
- [📋 Requirements](#requirements)
- [⚙️ Installation](#installation)
- [🚀 Usage](#usage)
- [💡 Example](#example)
- [🛠️ Error Handling](#error-handling)
- [📚 Resources](#resources)

## 📖 Overview

The project consists of two programs:

1. **Server** 🖥️: Receives and displays messages sent by the client.
2. **Client** 📨: Sends a string message to the server, one character at a time, using signals.

Communication is achieved through UNIX signals:
- `SIGUSR1` represents binary `0`
- `SIGUSR2` represents binary `1`

The server should handle messages sequentially without restarting.

## 🎯 Objectives

- Practice inter-process communication (IPC) with signals
- Encode and decode binary data using signals
- Handle concurrency with asynchronous signals
- Implement robust error handling

## 📋 Requirements

- **Programming Language**: C
- **Allowed Functions**: 
  - `write`
  - `malloc`
  - `free`
  - `getpid`
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`
- **Norminette**: Code must follow the Norminette style guide
- **Error Handling**: Handle all edge cases and errors gracefully

## ⚙️ Installation

Clone this repository and compile the project using `make`:

```bash
git clone https://github.com/HoudaChairi/42_minitalk.git
cd 42_minitalk
make
```

This will produce two executables:
- `server` 🖥️
- `client` 📬

## 🚀 Usage

### 1. Start the Server 🖥️

Run the server to get its PID (Process ID), which will be used by the client to send messages:

```bash
./server
```

The server will output its PID, which you'll use to send messages from the client.

### 2. Send a Message with the Client 📬

To send a message to the server, use the client with the server's PID and a message:

```bash
./client  "Your message here"
```

Example:
```bash
./client 12345 "Hello, server!"
```

## 💡 Example

1. Run the Server in one terminal:
```bash
./server
```
Expected output:
```
Server PID: 12345
```

2. Send a message with the Client from another terminal:
```bash
./client 12345 "Hello, 1337!"
```

The server terminal should display:
```
Received message: Hello, 1337!
```

## 🛠️ Error Handling

- The server should handle unexpected or out-of-sequence signals
- The client should display an error message if it cannot connect to the server or if an invalid PID is provided
- Handle cases like empty messages or very long messages as per the project requirements

## 📚 Resources

- Signal Handling in UNIX
- Inter-process Communication
