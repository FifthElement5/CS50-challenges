CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);