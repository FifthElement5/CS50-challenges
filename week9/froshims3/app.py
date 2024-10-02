# Implements e registration form, storing registrants in SQL database, with support for deregistration

from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

REGISTRANTS = {}

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name:
        return render_template("failure.html")
    if sport not in SPORTS:
        return render_template("failure.html")

    # remember registrants
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # confirm registration
    return redirect("/registrants")


@app.route("/deregister", methods=["POST"])
def deregister():

    # forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)