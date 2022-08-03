FROM ubuntu:latest

RUN /usr/sbin/useradd --no-create-home -u 1000 ctf

WORKDIR /home/ctf

RUN apt-get update
RUN apt-get install -y socat

COPY main flag.txt ./
RUN chmod +x main

RUN chown -R root:root /home/ctf

USER ctf

EXPOSE 1337

CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:"/home/ctf/main"
