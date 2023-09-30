import PermissionType from "./PermissionType";

interface DatabaseItem {
  email: string;
  password: string;
  permission: PermissionType;
}

const Database: DatabaseItem[] = [
  // cada chave aberto é um objeto da interface
  {
    email: "yorranan@email.com",
    password: "123456",
    permission: PermissionType.ADMIN,
  },
  {
    email: "conta@email.com",
    password: "abcdef",
    permission: PermissionType.USER,
  },
  {
    email: "teste.@email.com",
    password: "aa",
    permission: PermissionType.USER,
  }
];

export default Database;
