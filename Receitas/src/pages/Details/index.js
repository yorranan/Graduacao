import { useParams } from "react-router-dom";
import React, { useEffect, useState } from "react";

function Details() {
  const { id } = useParams();
  const [receita, setReceita] = useState({});

  useEffect(() => {
    fetch(`http://localhost:3000/posts/` + id)
      .then((response) => response.json())
      .then((data) => setReceita(data));
  }, [id]);

  return (
    <div className="container">
      <h2>{receita.nome}</h2>
    <ul>
      {receita.ingredientes?.map((ingrediente, index) => (
        <li key={index}>{ingrediente}</li>
      ))}
    </ul>
    <br/>
    <ol>
      {receita.modoPreparo?.map((modo, index) => (
        <li key={index}>{modo}</li>
      ))}
    </ol>
    </div>
  );
}

export default Details;
