document.addEventListener('DOMContentLoaded', () => {
  const themeToggle = document.getElementById('theme-toggle');
  const body = document.body;
  const form = document.getElementById('greet-form');
  const nameInput = document.getElementById('name-input');
  const message = document.getElementById('message');

  // Uloženie preferencie témy v localStorage (voliteľné)
  if (localStorage.getItem('theme') === 'dark') {
    body.classList.add('dark');
    themeToggle.textContent = 'Prepnúť na svetlý režim';
  }

  themeToggle.addEventListener('click', () => {
    const isDark = body.classList.toggle('dark');
    themeToggle.textContent = isDark ? 'Prepnúť na svetlý režim' : 'Prepnúť na tmavý režim';
    localStorage.setItem('theme', isDark ? 'dark' : 'light');
  });

  form.addEventListener('submit', (e) => {
    e.preventDefault();
    const name = nameInput.value.trim();
    if (!name) {
      message.textContent = 'Prosím napíš meno.';
      return;
    }
    message.textContent = `Ahoj, ${name}! 👋`;
    nameInput.value = '';
  });
});
