import React, { useEffect, useState } from "react";

function CreateNewRecipe() {
  const [newPost, setNewPost] = useState({
    id: "",
    nome: "",
    ingredientes: [],
    modoPreparo: [],
  });

  const [biggestId, setBiggestId] = useState(0);

  useEffect(() => {
    fetch("http://localhost:3000/posts")
      .then((response) => response.json())
      .then((data) => {
        const ids = data.map((post) => parseInt(post.id));
        setBiggestId(Math.max(...ids));
      })
      .catch((error) => {
        console.error("Error:", error);
      });
  }, []);

  const handleInputChange = (event) => {
    const { name, value } = event.target;
    setNewPost((prevState) => ({
      ...prevState,
      [name]: name === 'ingredientes' || name === 'modoPreparo' ? value.split(',') : value,
    }));
  };
  

  const handleSubmit = (event) => {
    event.preventDefault();

    const postWithBiggestId = {
      ...newPost,
      id: (biggestId + 1).toString(),
    };

    fetch("http://localhost:3000/posts", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(postWithBiggestId),
    })
      .then((response) => response.json())
      .then((data) => {
        console.log("Adicionado:", data);
      })
      .catch((error) => {
        console.error("Error:", error);
      });
  };

  return (
    <div>
      <h2>Nova Receita</h2>
      <p>Cuidado! Separe os ingredientes e os passos do modo de preparo por vírgulas.</p>
      <br/>
      <form onSubmit={handleSubmit}>
        <label htmlFor="nome">Nome:</label>
        <input
          type="text"
          id="nome"
          name="nome"
          value={newPost.nome}
          onChange={handleInputChange}
        />

        <label htmlFor="ingredientes">Ingredientes:</label>
        <input
          type="text"
          id="ingredientes"
          name="ingredientes"
          onChange={handleInputChange}
        />

        <label htmlFor="modoPreparo">Modo de Preparo:</label>
        <input
          type="text"
          id="modoPreparo"
          name="modoPreparo"
          onChange={handleInputChange}
        />

        <button type="submit">Add Post</button>
      </form>
    </div>
  );
}

export default CreateNewRecipe;
