FROM python:latest

WORKDIR /app

COPY ./aasa /app/apple-app-site-association
COPY ./aasa /app/.well-known/apple-app-site-association
COPY index.html .

CMD python3 -m http.server 1337
