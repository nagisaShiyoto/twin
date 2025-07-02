import socket

PORT = 1234
SERVER_IP = ""
MAX_MESSAGE_SIZE_DIGITS = 5

def main():
    listening_socket = socket.socket()
    listening_socket.bind(((SERVER_IP, PORT)))
    listening_socket.listen()
    client_socket, _ = listening_socket.accept()
    message = client_socket.recv(1024).decode()
    print(message)

if __name__ == "__main__":
    main()