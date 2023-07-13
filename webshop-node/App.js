//modul za pocetnu logiku
//koristimo xpres za startovanje http serverea
//npm moduli se ne instaliraju
//svakom modulu drzimo se samo jede celine
const express = require("express");
//inportovanje lokalinih modula
const router = require("./routes/api");
//sluzi za informacije od zahtevima
const logger = require("morgan");
const parser = require("body-parser");

const app = express();
//prihvata parametre razlicitih tipova
//parsira zahteve u json format
app.use(parser.urlencoded({ extended: true }));
app.use(parser.json());
app.use(logger("dev"));

app.use("/", router);

module.exports = app;
