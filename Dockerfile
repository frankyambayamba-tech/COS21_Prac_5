FROM gcc:latest

WORKDIR /user/src/campus_guard

COPY . .

RUN make

CMD ["./campus_guard"]