FROM nginx:latest

WORKDIR /usr/share/nginx/html

COPY index.html /usr/share/nginx/html

RUN apt-get update && apt-get install -y iputils-ping

EXPOSE 80

ENTRYPOINT [ "/usr/sbin/nginx" ]

CMD [ "-g","daemon off;" ]