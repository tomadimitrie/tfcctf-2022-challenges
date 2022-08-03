FROM ubuntu:latest

RUN /usr/sbin/useradd --no-create-home -u 1000 ctf

WORKDIR /home/ctf

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y socat libc6:i386

COPY main .
RUN chmod +x main

RUN chown -R root:root /home/ctf

USER ctf

EXPOSE 1337

CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:"/home/ctf/main"
