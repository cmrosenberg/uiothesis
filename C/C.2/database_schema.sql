CREATE TABLE entries (
 id     serial primary key,
 entry text NOT NULL,
 timestamp      timestamptz
);
