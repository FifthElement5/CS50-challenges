CREATE TABLE students (
    id INTEGER NOT NULL,
    student_name TEXT NOT NULL UNIQUE,
    PRIMARY KEY(id)
);
CREATE TABLE houses (
    id INTEGER NOT NULL,
    house TEXT NOT NULL UNIQUE,
    head TEXT NOT NULL UNIQUE,
    PRIMARY KEY(id)
);

CREATE TABLE assignment (
    id INTEGER,
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
);
INSERT INTO houses (house, head)
VALUES("Gryffindor", "Minerva McGonagall");

