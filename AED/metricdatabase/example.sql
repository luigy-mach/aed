
CREATE FUNCTION similar1_to(text,text) RETURN SETOF 

CREATE FUNCTION similar1_to(text,text) RETURNS SETOF pruebas AS $$
    SELECT * FROM pruebas WHERE campo1 <-> $2 <0.5;
$$ LANGUAGE SQL;

CREATE FUNCTION similar2_to(text,text) RETURNS boolean AS $$
    SELECT $1 <-> $2 <0.5;
$$ LANGUAGE SQL;

CREATE FUNCTION similar3_to(text,text,integer) RETURNS boolean AS $$
    SELECT $1 <-> $2 <0.5;
$$ LANGUAGE SQL;

CREATE FUNCTION similar4_to(text,text,integer) RETURNS boolean AS $$
BEGIN   
    IF char_length($1)>char_length($2) THEN
    RETURN $1 <-> $2 < (1.0/char_length($1))*$3; 
    ELSE
    RETURN $1 <-> $2 < (1.0/char_length($2))*$3;
    END IF;   
END;
$$ LANGUAGE plpgsql;

CREATE FUNCTION similar5_to(text,text,integer) RETURNS boolean AS $$
BEGIN   
    IF char_length($1)>char_length($2) THEN
    RETURN $1 <-> $2 <= (1.0/char_length($1))*$3; 
    ELSE
    RETURN $1 <-> $2 <= (1.0/char_length($2))*$3;
    END IF;   
END;
$$ LANGUAGE plpgsql;



CREATE FUNCTION MYSIMILAR_TO(text,text,integer) RETURNS boolean AS $$
BEGIN   
    IF char_length($1)>char_length($2) THEN
    RETURN $1 <-> $2 <= (1.0/char_length($1))*$3; 
    ELSE
    RETURN $1 <-> $2 <= (1.0/char_length($2))*$3;
    END IF;   
END;
$$ LANGUAGE plpgsql;





char_length('jose')
DECLARE
    l1 ALIAS FOR char_length($1);
    l2 ALIAS FOR char_length($2);
*
