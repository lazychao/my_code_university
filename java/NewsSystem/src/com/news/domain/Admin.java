package com.news.domain;

import lombok.Getter;
import lombok.Setter;

@Setter@Getter
public class Admin {
		private String id;
		private String username;
		private String password;
		@Override
		public String toString() {
			return "admin [id=" + id + ", username=" + username + ", password=" + password + "]";
		}
		
}
