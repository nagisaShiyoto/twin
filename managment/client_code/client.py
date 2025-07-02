import socket

PORT = 1234
SERVER_IP = "127.0.0.1"
MAX_MESSAGE_SIZE_DIGITS = 5

def main():
    
    ping_socket = socket.socket()
    ping_socket.connect((SERVER_IP, PORT))
    message = "asdasdasdasdasdasdjkflhns;lkjfn;ljshdjv"
    message_size = str(len(message))
    ping_socket.send(f"{message_size.zfill(MAX_MESSAGE_SIZE_DIGITS)}{message}".encode())
    message = ping_socket.recv(1024)
    print(message)

if __name__ == "__main__":
    main()